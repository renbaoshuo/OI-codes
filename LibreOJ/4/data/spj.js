exports.main = () => {
	code = code.trim().split('\r\n').join('\n');
	let outputCode = user_out.trim().split('\r\n').join('\n');
	if (code.length >= 10 && code === outputCode) exit({ score: 100 });
	else exit({ score: 0 });
}
