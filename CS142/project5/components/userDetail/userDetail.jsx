import React from 'react';
import {
  Typography,Grid,Button
} from '@material-ui/core';
import './userDetail.css';
import {Link} from 'react-router-dom';
import { cs142models } from '../../modelData/photoApp';
import fetchModel from '../../lib/fetchModelData';


/**
 * Define UserDetail, a React componment of CS142 project #5
 */
class UserDetail extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      user: null
    }
    var promise = fetchModel(`/user/${this.props.match.params.userId}`);
    promise.then(res=>{
      this.setState({user:res.data});
    })
    //最开始没有调用componentDidUpdate，user不能是空值
    
  }

  
  // componentDidUpdate = ()=>{
  //   let userId = this.props.match.params.userId;
  //   let userDetail = cs142models.userModel(userId);
  //   if(this.state.user._id != userId)
  //   {
  //     this.setState({user:userDetail});
  //   }

  // }
  render() {
    console.log(this.props)
    let userId = this.props.match.params.userId;
    let userDetail = cs142models.userModel(userId);
    this.state.user = userDetail
    // if(this.state.user._id != userId)
    // {
    // this.setState({user:userDetail});
    // }
    return (
      // <Typography variant="body1">
      //   This should be the UserDetail view of the PhotoShare app. Since
      //   it is invoked from React Router the params from the route will be
      //   in property match. So this should show details of user:
      //   {this.props.match.params.userId}. You can fetch the model for the
      //   user from window.cs142models.userModel(userId).
      // </Typography>
     this.state.user?(
       <Grid container
      justify="space-evenly"
      alignItems = "center"
       >
         <Grid xs={6} item>
           <Typography variant="h3">
           {`${this.state.user.first_name} ${this.state.user.last_name}`}
           </Typography>
           <Typography variant="h5">
          {this.state.user.occupation} <br />
          based in {this.state.user.location}
        </Typography>
        <Typography variant="body1">{this.state.user.description}</Typography>

         </Grid>
        <Grid xs={4} item>
          <Button variant="contained" size="large">
            <Link to = {`/photos/${this.state.user._id}`}>See Photo</Link>
          </Button>
        </Grid>
       </Grid>
     ):(<div />)
    );
  }
}

export default UserDetail;
