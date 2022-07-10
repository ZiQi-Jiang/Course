import React from 'react';
import ReactDOM from 'react-dom';
import Header from "./components/header/Header";
import Dynamic from './components/Dynamic/Dynamic';

ReactDOM.render(
    <div>
        <Header />
        <Dynamic />
    </div>,
    document.getElementById('reactapp'),
);