const fs = require('fs')

let str = fs.readFileSync(0).toString().replace(/\s+/g, ' ').split(' ');
let ans = []

str.forEach(word => {
    ans.push(word.length);
});

process.stdout.write(ans.join(','));
