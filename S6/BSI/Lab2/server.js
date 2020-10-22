var express = require('express');
var app = express();
var https = require('https');
var http = require('http');
var fs = require('fs');
var router = express.Router();
const axios = require('axios');
var jwt = require('jsonwebtoken');

const port = 443;
const restServer = "https://smirr.net:3000";
const token = jwt.sign({id: 2}, 'nieprawdopodobnySekret', {expiresIn: 120});

const httpsAgent = new https.Agent(
{
    rejectUnauthorized: false,
    cert: fs.readFileSync('sec/smirr.net.crt')
});

const httpsAxios = axios.create({ httpsAgent });

app.use(function(req, res, next) 
{
    if (req.secure) 
    {
        next();
    } 
    else 
    {
        res.redirect('https://' + req.headers.host + req.url);
    }
});

app.use(express.static(__dirname + '/public'));

app.use(express.json());

router.get('/', function(req, res, next)
{
    res.sendFile('index.html');
});

router.get('/rest', function(request, response)
{
    httpsAxios.get(restServer + '/basic', {
    auth: {
        username: "admin",
        password: "password"
    }})
    .then(function(res)
    {
        response.send(res.data);
    });
});

router.post('/rest', function(request, response)
{
    let data = {
        value: request.body.value
    };

    httpsAxios.post(restServer + '/basic', data, {
    auth: {
        username: "admin",
        password: "password"
    }})
    .then(function(res)
    {
        response.send(res.data);
    });
});

router.get('/restjwt', function(request, response)
{
    console.log(token);

    httpsAxios.get(restServer + '/jwt', {
    headers: {
        'Authorization': `Bearer ${token}`
    }})
    .then(function(res)
    {
        response.send(res.data);
    });
});

router.post('/restjwt', function(request, response)
{
    let data = {
        value: request.body.value
    };

    httpsAxios.post(restServer + '/jwt', data, {
    headers: {
        'Authorization': `Bearer ${token}`
    }})
    .then(function(res)
    {
        response.send(res.data);
    });
});

app.use('/', router);

http.createServer(app).listen(80);

https.createServer(
{
    key: fs.readFileSync('sec/smirr.org.key'),
    cert: fs.readFileSync('sec/smirr.org.crt')
}, app)
.listen(port, () => console.log(`Server started on port ${port}!`));
