// DO NOT MODIFIED

const getCharactersData = async function() {
    const response = await fetch("https://api.disneyapi.dev/character?page=2&pageSize=50")
    if (response.status == 200) {
        const data = await response.json()
        console.log(data.characters) // TO DELETE
        return data.characters
    } else {
        new Error(response.statusText)
    }
}

export default { getCharactersData }