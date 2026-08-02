// User data
const users = [
    { name: "Alice", age: 53 },
    { name: "Tim", age: 74 },
    { name: "Vijay", age: 67 },
    { name: "Vansh", age: 21 }
];

const fields = [
    "First Name",
    "Last Name",
    "Email"
];

function generateTable() {
    return `
        <table border="1" cellpadding="5">
            ${users.map(user => `
                <tr>
                    <td>${user.name}</td>
                    <td>${user.age}</td>
                </tr>
            `).join("")}
        </table>
    `;
}

function generateForm() {
    return `
        <form>
            ${fields.map(field => `
                <label>${field}</label><br>
                <input type="text"><br><br>
            `).join("")}
        </form>
    `;
}

document.getElementById("table-container").innerHTML = generateTable();
document.getElementById("form-container").innerHTML = generateForm();