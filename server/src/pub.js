const mqtt = require('mqtt');
const client = mqtt.connect('mqtt://localhost:1234')
const topic = 'TEST123'
const message = 'Hello World!'

client.on('connect', () => {
    setInterval(() => {
        try {
            client.publish(topic, message)
            console.log('Message sent: ', message)
        } catch (err) {
            console.log("deu merda");
        }
    }, 5000)
})