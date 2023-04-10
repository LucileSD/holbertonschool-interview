#!/usr/bin/node

const request = require('request');
const url = 'https://swapi-api.hbtn.io/api/films/' + process.argv[2];

request.get(url, async (error, response, body) => {
  if (error) {
    console.log(error);
  } else {
    for (const character of JSON.parse(body).characters) {
      const name = await new Promise((resolve, reject) => {
        request.get(character, (error, response, body) => {
          if (error) {
            reject(error);
          } else {
            resolve(JSON.parse(body).name);
          }
        });
      });
      console.log(name);
    }
  }
});
