'use strict';

/*
 * A simple Node.js program for exporting the current working directory via a webserver listing
 * on a hard code (see portno below) port. To start the webserver run the command:
 *    node webServer.js
 *
 * Note that anyone able to connect to localhost:3001 will be able to fetch any file accessible
 * to the current user in the current directory or any of its children.
 */

/* jshint node: true */

var express = require('express');

var portno = 3000;   // Port number to use

var app = express();

var cs142models = require('./modelData/photoApp.js').cs142models;

// We have the express static module (http://expressjs.com/en/starter/static-files.html) do all
// the work for us.
app.use(express.static(__dirname));
//app.use的意思是，使用一个中间件，它有两个参数，第一个是root地址，默认是‘/’，后面是一个回调函数，这里的意思是：
//每当浏览器请求一个页面时（因为‘/’和所有url都可以匹配），我们都使用app.use里面规定的函数处理，（这个函数处理后
// 可以再调用next（）使用app.get等其他函数，此时就是一个中间件）
//express.static是一个函数，它的作用是提供静态文件（所有用户都相同的文件），这里第一个参数忽略了，会自动解析成‘index.html'
// 然后会根据__dirname指定的目录里寻找root对应的文件，找到就直接返回，没找着就next调用app.get继续解析路由
//

app.get('/', function (request, response) {
  response.send('Simple web server of files from ' + __dirname);
});

app.get('/test/:p1', function (request, response) {
  // Express parses the ":p1" from the URL and returns it in the request.params objects.
  var param = request.params.p1;
  console.log('/test called with param1 = ', param);
  if (param !== "info") {
    console.error("Nothing to be done for param: ", param);
    response.status(400).send('Not found');
    return;
  }
  
  var info = cs142models.schemaInfo();
  
  // Query didn't return an error but didn't find the SchemaInfo object - This
  // is also an internal error return.
  if (info.length === 0) {
    response.status(500).send('Missing SchemaInfo');
    return;
  }
  response.status(200).send(info);
});

/*
 * URL /user/list - Return all the User object.
 */
app.get('/user/list', function (request, response) {
  console.log('userlist')
  response.status(200).send(cs142models.userListModel());
  return;
});

/*
 * URL /user/:id - Return the information for User (id)
 */
app.get('/user/:id', function (request, response) {
  var id = request.params.id;
  console.log(123)
  var user = cs142models.userModel(id);
  if (user === null) {
    console.log('User with _id:' + id + ' not found.');
    response.status(400).send('Not found');
    return;
  }
  
  // response.status(200).send(user);
  return;
});

/*
 * URL /photosOfUser/:id - Return the Photos for User (id)
 */
app.get('/photosOfUser/:id', function (request, response) {
  var id = request.params.id;
  var photos = cs142models.photoOfUserModel(id);
  if (photos.length === 0) {
    console.log('Photos for user with _id:' + id + ' not found.');
    response.status(400).send('Not found');
    return;
  }
  response.status(200).send(photos);
});


var server = app.listen(portno, function () {
  var port = server.address().port;
  console.log('Listening at http://localhost:' + port + ' exporting the directory ' + __dirname);
});
//启动流程：我们监听3000port，然后打开对应端口，这个时候本文件（服务器）就可以接受到请求，url是根目录，首先调用
//express.static查找，/先解析成index.html,(express默认行为)，然后发现确实有index.html,所以直接返回index.html不经过app.get
