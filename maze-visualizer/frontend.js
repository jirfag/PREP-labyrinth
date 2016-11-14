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
            console.log(steps);
        }

    }
}

var j = 0;
function previous() {
    if (j) {
        --j;
    }
    
    var id = (parseInt(startPoint[0]) + parseInt(steps[j][0])) + ":" + (parseInt(startPoint[1]) + parseInt(steps[j][1]));
    console.log(id + ":" + steps[j][2]);
    document.getElementById(id).innerHTML = "";
    document.getElementById(id).style.backgroundColor = "white";
    document.getElementById(id).style.color = "black";

}

function next() {
    var id = (parseInt(startPoint[0]) + parseInt(steps[j][0])) + ":" + (parseInt(startPoint[1]) + parseInt(steps[j][1]));
    console.log(id + ":" + steps[j][2]);
    document.getElementById(id).innerHTML = steps[j][2];
    document.getElementById(id).style.backgroundColor = "purple";
    document.getElementById(id).style.color = "white";

    ++j;
}

