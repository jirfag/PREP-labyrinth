var steps = [];
var startPoint = [];

window.onload = function() {

    handleMazeFile();
    handleStepsFile();
};

function handleMazeFile() {
    var xhr = new XMLHttpRequest();

    xhr.open('GET', 'mazeFile', true);
    xhr.send();

    xhr.onreadystatechange = function() {
        if (xhr.readyState != 4) return;

        if (xhr.status != 200) {
            alert(xhr.status + ': ' + xhr.statusText);
        } else {
            var maze = JSON.parse(xhr.responseText);
            maze.forEach(function(row, i, arr) {
                var rowElement = document.createElement("TR");

                row.forEach(function(item, j, arr2) {
                    if (item == 2) {
                        startPoint[1] = maze.length - 1 - i;
                        startPoint[0] = j;
                    }
                    var cellElement = document.createElement("TD");
                    cellElement.className = "i" + item;
                    cellElement.id = j + ":" + (maze.length - 1 - i);

                    rowElement.appendChild(cellElement);
                });

                document.getElementsByTagName("table")[0].appendChild(rowElement);
            });
        }
    }
    
};

function handleStepsFile() {
    var xhr = new XMLHttpRequest();

    xhr.open('GET', 'steps', true);
    xhr.send();

    xhr.onreadystatechange = function() {
        if (xhr.readyState != 4) return;

        if (xhr.status != 200) {
            alert(xhr.status + ': ' + xhr.statusText);
        } else {
            steps = JSON.parse(xhr.responseText);
        }

    }
}

var j = 0;

function solve() {
    var i = j;
    var timeId = setInterval(function() {
        var id = (parseInt(startPoint[0]) + parseInt(steps[i][0])) + ":" + (parseInt(startPoint[1]) + parseInt(steps[i][1]));

        document.getElementById(id).innerHTML = steps[i][2];

        if (steps[i][2] == 1) {
            document.getElementById(id).style.backgroundColor = "green";
            document.getElementById(id).style.color = "white";
        } else if (steps[i][2] == 2) {
            document.getElementById(id).style.backgroundColor = "yellow";
            document.getElementById(id).style.color = "black";
        } else {
            document.getElementById(id).style.backgroundColor = "red";
            document.getElementById(id).style.color = "white";
        }

        ++i;
        if (i == steps.length)
            clearInterval(timeId);

    }, 100);
}

function next() {
    var id = (parseInt(startPoint[0]) + parseInt(steps[j][0])) + ":" + (parseInt(startPoint[1]) + parseInt(steps[j][1]));
    document.getElementById(id).innerHTML = steps[j][2];
    if (steps[j][2] == 1) {
        document.getElementById(id).style.backgroundColor = "green";
        document.getElementById(id).style.color = "white";
    } else if (steps[j][2] == 2) {
        document.getElementById(id).style.backgroundColor = "yellow";
        document.getElementById(id).style.color = "black";
    } else {
        document.getElementById(id).style.backgroundColor = "red";
        document.getElementById(id).style.color = "white";
    }

    ++j;
}

