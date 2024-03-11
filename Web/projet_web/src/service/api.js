const getRatpData = async function() {
    const response = await fetch("https://api-ratp.pierre-grimaud.fr/v4/")
    if (response.status == 200) {
    return await response.json()
    } else {
    new Error(response.statusText)
    }
    }
    export { getRatpData }

fetch(
    "",
    {
        method: "POST", // or GET, PUT, DELETE, etc.
        headers: {
            "Content-Type": "application/json" // to have JSON content in body
    'Authorization': 'Bearer ' + myToken, // set JWT token
        },
        body: JSON.stringify(myData) // set JSON data in request body
    }
)

