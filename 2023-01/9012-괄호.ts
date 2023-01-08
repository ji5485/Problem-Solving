import { readFileSync } from "fs";

const [_, ...arr] = readFileSync("/dev/stdin").toString().trim().split("\n");

arr.forEach((ps: string) => {
  let stack = 0,
    flag = true;

  ps.split("").forEach((str: string) => {
    if (!flag || stack < 0) {
      flag = false;
      return;
    }

    if (str === "(") stack++;
    else stack--;
  });

  console.log(flag && stack === 0 ? "YES" : "NO");
});
