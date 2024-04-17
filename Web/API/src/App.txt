
<template>
  <div class="app">
    <Header @search="searchCharacter" />
    <Background :characters="displayedCharacters" />
  </div>
</template>
<script>
import Header from "./components/Header.vue";
import Background from "./components/Background.vue";

export default {
  components: {
    Header,
    Background,
  },
  data() {
    return {
      characters: [],
      displayedCharacters: [],
    };
  },
  methods: {
    searchCharacter(searchQuery) {
      // Filtrer les personnages correspondants à la recherche
      this.displayedCharacters = this.characters.filter((character) => {
        return character.name.toLowerCase().includes(searchQuery.toLowerCase());
      });
    },
    handleSearchResults(results) {
      this.displayedCharacters = results;
    },
  },
  mounted() {
    const storedCharacters = localStorage.getItem("characters");
    if (storedCharacters) {
      this.characters = JSON.parse(storedCharacters);
      this.displayedCharacters = this.characters.slice(5, 20);
      // this.displayedCharacters = this.characters.filter(character => character.name == "Achilles"); // On obtient le résultat Achilles
    } else {
      this.fetchCharacters();
    }
  },
  methods: {
    shuffle(array) {
      for (let i = array.length - 1; i > 0; i--) {
        const j = Math.floor(Math.random() * (i + 1));
        [array[i], array[j]] = [array[j], array[i]];
      }
      return array;
    },
    mounted() {
      fetch("http://api.disneyapi.dev/character?page=2&pageSize=100")
        .then((response) => response.json())
        .then((data) => {
          if (data && Array.isArray(data.data)) {
            this.characters = data.data.slice(0, 20);
          } else {
            console.error("Invalid response data format");
          }
        })
        .catch((error) => console.error("Error fetching characters", error));
    },
  },
};
</script>

<style>
.app {
  text-align: center;
  background: linear-gradient(to bottom, #83d6c3, #7cacfb);
  min-height: 100vh;
}
</style>

