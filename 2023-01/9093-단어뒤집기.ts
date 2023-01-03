import { readFileSync } from "fs";

const [_, ...arr] = readFileSync("input.txt").toString().trim().split("\n");

arr.forEach((str) =>
  console.log(
    str
      .split(" ")
      .map((str) => str.split("").reverse().join(""))
      .join(" ")
  )
);
