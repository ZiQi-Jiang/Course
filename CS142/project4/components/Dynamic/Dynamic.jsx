import React from "react";
import Example from "../example/Example";
import './Dynamic.css';
import States from "../states/States";

class Dynamic extends React.Component{
    constructor(props){
        super(props);
        this.state = {
            choice: 0,
        }
    }

    render(){
        
        return (
            <div>
               <button onClick={()=>{this.setState({choice:(this.state.choice+1)%2})}}> Switch To {this.state.choice?'Example':'States'}</button>
                {this.state.choice?<States/>:<Example/>}
                {/* <States /> */}
            </div>
        )
    }

}


export default Dynamic;