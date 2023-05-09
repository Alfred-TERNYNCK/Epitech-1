const express = require('express')
const app = express()
const dotenv = require('dotenv').config()
const port = 3000
const router = express.Router();
const bodyParser = require("body-parser")
const jwt = require('jsonwebtoken');
const mysql = require('mysql');
const path = require('path');

app.use(express.urlencoded({ extended: true }))
app.param('name', function(req, res, next, name) {
  req.name = name;
  next();
});

const db = mysql.createConnection({
    host: process.env.MYSQL_HOST,
    user: process.env.MYSQL_USER,
    password: process.env.MYSQL_ROOT_PASSWORD,
    database: process.env.MYSQL_DATABASE
});

db.connect(function(err) {
  if (err) {
    console.error('error connection');
    return;
}
console.log('connected as id ' + db.threadId);
});
module.exports = db;

app.post("/register", (req , res) => {
    db.query("INSERT INTO `user`(email, password, name, firstname) VALUES (?, ?, ?, ?)", [req.body["email"], req.body["password"], req.body["name"], req.body["firstname"]], function(err, results, fields){
        if (err)
            throw err;
    });
});

app.post("/login", (req , res) => {
    ;
});

app.get("/", (req , res) => {
    res.sendFile(path.join(__dirname + '/home.html'));
});

app.get("/user", (req , res) => {
    res.send('information of all user');
});

app.get("/user/todos", (req , res) => {
    res.send('all tasks dude');
});
app.get("/user/:id", (req , res) => {
    res.send('information of you');
});

app.get("/user/:email", (req , res) => {
    res.send('view user information');
});

app.put("/user/:id", (req , res) => {
    ;
});

app.delete("/user/:id", (req , res) => {
    var id = req.params.id;

    delete_task_by_id(res, id);
});

app.get("/todos", (req , res) => {
    res.send('all task of everyone');
});

app.get("/todos/:id", (req , res) => {
    res.send('your task');
});

app.post("/todo", (req , res) => {
    ;
});

app.put("/todos/:id", (req , res) => {
    ;
});

app.delete("/todos/:id", (req , res) => {
    ;
});

app.listen(port , () => {
    console.log(`Example app listening at http :// localhost:${port}`);
});
