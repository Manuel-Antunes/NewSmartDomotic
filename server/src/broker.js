const mosca = require('mosca');
const broker = new mosca.Server({ port: 1234 })

broker.on('ready', () => {
    console.log('Broker is ready');
})
broker.on('subscribed', (data) => {
    console.log('entraram');
    console.log(data);
})