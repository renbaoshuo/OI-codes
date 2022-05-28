exports.main = () => {
	code = code.trim().split('\r\n').join('\n');
	let outputCode = user_out.trim().split('\r\n').join('\n');
	if (code.length >= 10 && code === outputCode) exit({ score: 100 });
	else exit({ score: 0 });
}

function exit(obj) {
  process.stdout.write(String(obj.score));
  if (obj.message) process.stderr.write(String(obj.message));
  process.exit();
}

let fs = require('fs');
let input = fs.readFileSync('input').toString();
let user_out = fs.readFileSync('user_out').toString();
let answer = fs.readFileSync('answer').toString();
let code = fs.readFileSync('code').toString();
exports.main();
