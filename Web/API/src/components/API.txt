const getCharacterData = async function() {
    const response = await fetch("http://api.disneyapi.dev/character")
    if (response.status == 200) {
        const data = await response.json()
        console.log(data.characters) // DELETE
        return data.characters
    } else {
        new Error(response.statusText)
    }
}

export default { getCharacterData }