/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
 const isMatch = (s, p) => new RegExp(`^${p}$`).test(s);
