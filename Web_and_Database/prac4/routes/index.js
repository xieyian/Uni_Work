var express = require('express');
var router = express.Router();


/* GET home page. */
router.get('/', function(req, res, next) {
  res.render('index', { title: 'Express' });
});

//3.1
 var time;
  router.get('/last.txt',function(req, res, next) {
             time = Date();
             res.send('<!DOCTYPE html> \
                      <html> \
                      <head> \
                      <title>3.1</title> \
                      <style></style> \
                      </head> \
                      <body><h1>The time is '+ time +'</h1></body> \
                      </html>');
                      
});


//3.2
var count=0;
router.get('/colour.html',function(req, res, next){
           count++;
           if(count%4==1){
           res.send('<!DOCTYPE html> \
                    <html> \
                    <head> \
                    <title>3.2</title> \
                    <style></style> \
                    </head> \
                    <body><h1 style="color:red">red</h1></body> \
                    </html>');
           }
           if(count%4==2){
           res.send('<!DOCTYPE html> \
                    <html> \
                    <head> \
                    <title>3.2</title> \
                    <style></style> \
                    </head> \
                    <body><h1 style="color:yellow">yellow</h1></body> \
                    </html>');

           }
           if(count%4==3){
           res.send('<!DOCTYPE html> \
                    <html> \
                    <head> \
                    <title>3.2</title> \
                    <style></style> \
                    </head> \
                    <body><h1 style="color:green">green</h1></body> \
                    </html>');

           }
           if(count%4==0){
           res.send('<!DOCTYPE html> \
                    <html> \
                    <head> \
                    <title>3.2</title> \
                    <style></style> \
                    </head> \
                    <body><h1 style="color:blue">blue</h1></body> \
                    </html>');

           }
           
           });



var countt=0;
router.get('/colour.txt',function(req, res, next){
           countt++;
           if(countt%4==1){
           res.send('red');
           }
           if(countt%4==2){
           res.send('yellow');
           
           }
           if(countt%4==3){
           res.send('green');
           
           }
           if(countt%4==0){
           res.send('blue');
           }
           });





//3.3
var times="";
router.get('/log.html',function(req, res, next) {
           times += '<li>'+Date()+'</li>';
           res.send('<!DOCTYPE html> \
                    <html  lang = "en-US"> \
                    <head> \
                    <meta charset = "UTF-8">\
                    <title>3.3</title> \
                    </head> \
                    <body>\
                    <ul>'+ times+'</ul>\
                    </body>\
                    </html>');
        
           
           });

//4.1


module.exports = router;


