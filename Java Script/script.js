let users = {
  data: {},

  buyCourse: function(username, course) {
    if (!this.data[username]) {
      console.log(`${username} does not exist.`);
      return;
    }
    this.data[username].courselist.push(course);
  },

  getCourse: function(username) {
    if (!this.data[username]) {
      console.log(`${username} does not exist.`);
      return;
    }
    return `${this.data[username].firstname} is enrolled in total ${this.data[username].courselist.length} courses`;
  },

  addUser: function(firstname, lastname) {
    let username = firstname.toLowerCase();
    this.data[username] = {
      firstname: firstname,
      lastname: lastname,
      courselist: []
    };
  }
};

// Adding users
users.addUser("Snehal", "Pinninti");
users.addUser("Ravi", "Kumar");

// Buying courses
users.buyCourse("snehal", "Java");
users.buyCourse("snehal", "Python");
users.buyCourse("ravi", "C++");

// Displaying course details
console.log(users.getCourse("snehal")); // Snehal is enrolled in total 2 courses
console.log(users.getCourse("ravi"));   // Ravi is enrolled in total 1 course