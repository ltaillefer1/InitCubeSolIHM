var ctx = document.getElementById('myChart').getContext('2d');
var myChart = new Chart(ctx, {
    type: 'line',
    data: {
        labels: ["1", "2", "3", "4", "5", "6", "7", "8", "9", "10"],
        datasets: [{
            label: 'Temperature systeme',
            data: [],
            borderWidth: 2,
            borderColor: ['red'],
        }, {
            label: 'Temperature processeur',
            data: [],
            borderWidth: 2,
            borderColor: ['green'],
        }, {
            label: 'Temperature batterie',
            data: [],
            borderWidth: 2,
            borderColor: ['yellow'],
        }, {
            label: 'Temperature caméra',
            data: [],
            borderWidth: 2,
            borderColor: ['aqua'],
        }, {
            label: 'Temperature Test',
            data: [],
            borderWidth: 2,
            borderColor: ['white'],
        }]

    },
    options: {
        scales: {
            yAxes: [{
                ticks: {
                    beginAtZero: true
                }
            }]
        }
    }
});
for (var i = 0; i < 10; i++) {
            myChart.data.datasets[0].data[i] = myChart.data.datasets[0].data[i + 1];
            myChart.data.datasets[1].data[i] = myChart.data.datasets[1].data[i + 1];
            myChart.data.datasets[2].data[i] = myChart.data.datasets[2].data[i + 1];
            myChart.data.datasets[3].data[i] = myChart.data.datasets[3].data[i + 1];
            myChart.data.datasets[4].data[i] = myChart.data.datasets[4].data[i + 1];
        };
        myChart.data.datasets[0].data[10] = obj.temp;
        myChart.data.datasets[1].data[10] = obj.temp1;
        myChart.data.datasets[2].data[10] = obj.temp2;
        myChart.data.datasets[3].data[10] = obj.temp3;
        myChart.data.datasets[4].data[10] = obj.temp4;
        myChart.update();