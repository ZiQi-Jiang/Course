import React from 'react';
import './States.css';
import Header from '../header/Header';
/**
 * Define States, a React componment of CS142 project #4 problem #2.  The model
 * data for this view (the state names) is available
 * at window.cs142models.statesModel().
 */
class States extends React.Component {
  constructor(props) {
    super(props);
    console.log('window.cs142models.statesModel()', window.cs142models.statesModel());
    this.state = {
      subString:''
    }
  }

  render() {
    var data = window.cs142models.statesModel().sort();
    var length = data.length;
    var listItems = [];
    for(var i = 0; i< length; i ++ )
    {
      if(data[i].toLowerCase().match(this.state.subString.toLowerCase()))
      listItems[i] = <li key = {i}>{data[i]}</li>
    }
    return (
  
      <div>
         <Header/>
        Input a subString:
        <input value={this.state.subString} onChange={ e=>{this.setState({subString:e.target.value})}}></input>
        <div>
          {listItems}
        </div>
      </div>
    
    
    );
  }
}

export default States;
