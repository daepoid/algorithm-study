function solution(line) {
  let set = new Set();
  let u = -1, d = 1, r = -1, l = 1;

  for (let i = 0; i < line.length - 1; i++) {
    for (let j = 0; j < line.length; j++) {
      const [a, b, c] = line[i];
      const [d, e, f] = line[j];

      const x = (f * b - c * e) / (a * e - d * b);
      const y = (c * d - a * f) / (a * e - d * b);
      if (x === Math.floor(x) && y === Math.floor(y)) {
        r = Math.max(r, x);
        l = Math.min(l, x);
        u = Math.max(u, y);
        d = Math.min(d, y);
        set.add([x, y]);
      }
    }
  }
  let answer = new Array(u - d + 1).fill('.'.repeat(r - l + 1))

  for (const el of set) {
    answer[u - el[1]] = answer[u - el[1]].substring(0, el[0] - l) + "*" + answer[u - el[1]].substring(el[0] - l + 1);
  }

  return answer;
}

function main() {
  // const line = [
  //   [2, -1, 4],
  //   [-2, -1, 4],
  //   [0, -1, 1],
  //   [5, -8, -12],
  //   [5, 8, 12],
  // ];

  const line = 	[[0, 1, -1], [1, 0, -1], [1, 0, 1]];
  let result = solution(line);
  result.forEach(r => console.log(r.toString()));
}

main();
