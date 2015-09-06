var readline = require('readline');
var rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
  terminal: false
});

rl.on('line', function(line){
    var num = parseInt(line);
    if (num == 42) {
        process.exit();
    }
    else {
        console.log(line);
    }
})
