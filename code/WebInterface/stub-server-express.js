const express = require('express');
const bodyParser = require('body-parser');
const fs = require('fs');
const multer = require('multer');
const path = require('path');
const HTTP_CODE = require('http-status');


const port = 8087;

const webinterface_html_file = 'index.html';
const webinterface_css_file = 'style.css';
const webinterface_index_js_file = 'index.js';
const webinterface_repsitory_js_file = 'repository.js';

const busiess_state = {};

const app = express();
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true })); 

app.get('/', (_, response) => {
    response.sendFile(webinterface_html_file, { root: __dirname });
});


app.get('/style.css', (_, response) => {
    response.sendFile(webinterface_css_file, { root: __dirname });
});


app.get('/index.js', (_, response) => {
    response.sendFile(webinterface_index_js_file, { root: __dirname });
});


app.get('/repository.js', (_, response) => {
    response.sendFile(webinterface_repsitory_js_file, { root: __dirname });
});


app.get('/api/ping', (_, response) => {
    setTimeout(
        () => {
            response.status(HTTP_CODE.OK).json({
                status: 'ok',
            });
        },
        200
    );
});


app.get('/api/business-state', (request, response) => {
    response.status(200).json(busiess_state);
});


app.listen(port, () => {
  console.log(`Vintage camera stub server listening on port ${port}`)
})
