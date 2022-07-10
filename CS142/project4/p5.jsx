import React from 'react';
import ReactDOM from 'react-dom';
import Example from "./components/example/Example";
import States from './components/states/States';
import {HashRouter, BrowserRouter,Route, Link} from "react-router-dom";
ReactDOM.render(
    <div>
        <BrowserRouter>
        <ul>
            <li>
        <Link to="states">States</Link>
        </li>
        <li>
        <Link to="examples">Examples</Link>
        </li>
        </ul>
            <Route path = "/states" component={States} />
            <Route path = "/examples" component={Example} />
    
        </BrowserRouter>
        
    </div>,
    document.getElementById('reactapp'),
);