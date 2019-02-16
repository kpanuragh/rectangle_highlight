const rectangle_highlight=require("./index");
const fs=require('fs');
console.time("test");
let data=rectangle_highlight.draw("C:/Users/ACODEZ/RD/rectangle_highlight/gp008.png","C:/Users/ACODEZ/RD/rectangle_highlight/Telecommunicati008_out.png",1691, 2057,1886, 2295);
console.log(data);
console.timeEnd("test");
