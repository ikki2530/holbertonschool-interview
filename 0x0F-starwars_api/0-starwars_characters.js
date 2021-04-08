#!/usr/bin/node
const request = require('request');

request('https://swapi-api.hbtn.io/api/films/' + process.argv[2], async function (err, response, body) {
  if (err) {
    console.log(err);
  } else {
    const mylist = JSON.parse(body).characters;
    for (const i in mylist) {
      const req = new Promise((resolve, reject) => {
        request(mylist[i], function (err, response, body) {
          if (err) {
            reject(err);
          } else {
            resolve(body);
          }
        });
      });
      await req.then(body => console.log(JSON.parse(body).name)).catch(err => console.log(err));
    }
  }
});
