import React from 'react';
import {
  Divider,
  List,
  ListItem,
  ListItemText,
  Typography,
  Grid,
}
from '@material-ui/core';
import './userList.css';
import { cs142models } from '../../modelData/photoApp';
import {Link} from 'react-router-dom';// material-UI和react-router-dom都有Link，注意区分，react的LInk才有to属性
import fetchModel from '../../lib/fetchModelData';
/**
 * Define UserList, a React componment of CS142 project #5
 */
class UserList extends React.Component {
  constructor(props) {
    super(props);
    this.state = {userList:null};
    fetchModel(`http://localhost:3000/user/list`).then(response=>{
      this.setState({userList: response.data});
    })

  }

  //同步的时候可以在render里面获取模型，但是异步的话，只能利用Promise获取模型后setState

  render() {
    return (
      <div>
        {/* <Typography variant="body1">
          This is the user list, which takes up 3/12 of the window.
          You might choose to use <a href="https://material-ui.com/demos/lists/">Lists</a> and <a href="https://material-ui.com/demos/dividers">Dividers</a> to
          display your users like so:
        </Typography> */}
        <List component="nav">
        {
          this.state.userList?this.state.userList.map((item)=>{
            return <Link to={`/users/${item._id}`} key={item._id}><ListItem>
              <ListItemText primary={item.first_name + item.last_name} secondary={item.location + "," + item.occupation} />
            </ListItem><Divider/></Link>
          }):(<div/>)
        }
        </List>
        {/* <List component="nav">
          <ListItem>
            <ListItemText primary="Item #1" />
          </ListItem>
          <Divider />
          <ListItem>
            <ListItemText primary="Item #2" />
          </ListItem>
          <Divider />
          <ListItem>
            <ListItemText primary="Item #3" />
          </ListItem>
          <Divider />
        </List>
        <Typography variant="body1">
          The model comes in from window.cs142models.userListModel()
        </Typography> */}
      </div>
    );
  }
}

export default UserList;
