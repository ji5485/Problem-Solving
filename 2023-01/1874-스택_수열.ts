import { readFileSync } from "fs";

const [n, ...arr]: number[] = readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n")
  .map((item: string) => parseInt(item));

function solution(n: number, arr: number[]) {
  const stack = [];
  const result = [];
  let pivot = 1;

  for (let i = 0; i < n; i++) {
    while (pivot <= arr[i]) {
      result.push("+");
      stack.push(pivot);
      pivot++;
    }

    do {
      if (stack.length === 0) return "NO";
      result.push("-");
    } while (stack.pop() !== arr[i]);
  }

  return result.join("\n");
}

console.log(solution(n, arr));
