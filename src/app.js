const express = require('express');
const app = express();
const port = 3000;
app.use(express.static(__dirname));
const server = app.listen(port, () => {
    console.log("Listening on port: " + port);
});

const { SerialPort } = require('serialport');
const serialport = new SerialPort({ path: 'COM3', baudRate: 115200 });
const io = require('socket.io')(server);
io.on('connection', function(socket) {
    socket.on('senddata',function(data){      
        // console.log(data);
        serialport.write(data);

    });
});

serialport.on('readable', function () {
    const info = serialport.read().toString();
    if(info != null)
        console.log('Data:', info);
});