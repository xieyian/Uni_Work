
var express = require('express');
var router = express.Router();
var bodyParser = require('body-parser');
var app = express();
app.use( bodyParser.json() );       // to support JSON-encoded bodies
app.use(bodyParser.urlencoded({     // to support URL-encoded bodies
                              extended: true
                              }));

var wdc=[];



router.get('/getposts', function(req, res, next) {
           res.json(wdc);
});


router.post('/addpost', function(req, res) {
            wdc.push(req.body);
            res.send(wdc);
            });

module.exports = router;

