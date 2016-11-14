var express = require('express');
var app = express();
var fs = require('fs');
const readline = require('readline');

const stepsFile = "../steps.txt";
const mazeFile = "../test_labs/test_lvl_5.txt";
var map = [];
var steps = [];
var rows, columns;

var rl = readline.createInterface({
    input: fs.createReadStream(mazeFile)
});

var i = 0;
rl.on('line', (line) => {
    const arr = line.split(' ');

    if (i === 0) {
        rows = arr[0];
        columns = arr[1];
    } else {
        arr.splice(arr.length - 1, 1)
        map.push(arr);
    }

    if (i == rows) {
        console.log('yep');
        rl.close();
        rl = readline.createInterface({
            input: fs.createReadStream(stepsFile)
        });
        rl.on('line', (line) => {
            const arr2 = line.split(' ');

            arr2.splice(arr.length - 1, 1)
            steps.push(arr2);
        });
    }
    ++i;
});

app.use(express.static(__dirname + '/'));

app.get('/mazeFile', function (req, res) {
    res.send(JSON.stringify(map));
});

app.get('/steps', function (req, res) {
    res.send(JSON.stringify(steps));
});


var server= app.listen(8080, function () {
  console.log('8080');
});
