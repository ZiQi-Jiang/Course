import React from 'react';
import {
  CardMedia,
  Typography,
  Card
} from '@material-ui/core';
import './userPhotos.css';
import { cs142models } from '../../modelData/photoApp';
import fetchModel from '../../lib/fetchModelData';


/**
 * Define UserPhotos, a React componment of CS142 project #5
 */
class UserPhotos extends React.Component {
  constructor(props) {
    super(props);
    this.state =  {
      photos:null
    }
    var promise = fetchModel(`/photosOfUser/${this.props.match.params.userId}`);
    promise.then(res=>{
      this.setState({photos:res.data[0]})
    })
  }

  render() {
  
    return (
      // <Typography variant="body1">
      // This should be the UserPhotos view of the PhotoShare app. Since
      // it is invoked from React Router the params from the route will be
      // in property match. So this should show details of user:
      // {this.props.match.params.userId}. You can fetch the model for the user from
      // window.cs142models.photoOfUserModel(userId):
      //   <Typography variant="caption">
      //     {JSON.stringify(window.cs142models.photoOfUserModel(this.props.match.params.userId))}
      //   </Typography>
      // </Typography>
      this.state.photos?
      <Card>
        <CardMedia 
          component="img"
          height="140"
          image={`./images/${this.state.photos.file_name}`}
        />
      </Card>:<div/>

    );
  }
}

export default UserPhotos;
