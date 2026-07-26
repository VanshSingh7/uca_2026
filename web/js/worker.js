// on console

// self.onmessage = async function () {
//     try {
//         //real public api
//         const response = await fetch("https://dummyjson.com/users");

//         if (!response.ok) {
//             throw new Error(`HTTP Error: ${response.status}`);
//         }

//         const data = await response.json();

//         if (!data.users || data.users.length === 0) {
//             self.postMessage({
//                 error: "No users returned from API."
//             });
//             return;
//         }

//         const users = data.users.map(user => ({
//             name: `${user.firstName} ${user.lastName}`,

//             //dummy.json donot have this field we generate it
//             status: user.id % 2 === 0 ? "Active" : "Inactive" 
//         }));

//         self.postMessage(users);

//     } catch (error) {
//         self.postMessage({
//             error: "Error fetching users: " + error.message
//         });
//     }
// };


// on UI

self.onmessage = async function () {

    try {

        const response = await fetch("https://dummyjson.com/users");

        if (!response.ok) {
            throw new Error("Failed to fetch users");
        }

        const data = await response.json();

        if (!data.users || data.users.length === 0) {

            self.postMessage({
                error: "No users found"
            });

            return;
        }

        const users = data.users.map(user => ({

            name: `${user.firstName} ${user.lastName}`,

            // dummyjson has no active field,
            // so we create one for demonstration.
            active: user.id % 2 === 0

        }));

        self.postMessage(users);

    }
    catch (err) {

        self.postMessage({
            error: err.message
        });

    }

};