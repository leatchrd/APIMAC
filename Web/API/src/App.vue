<template>
  <Header :characters="characters" @filter-change="handleFilterChange" />
  <CharacterCard
    v-for="(character, index) in characters"
    :key="character._id || index"
    :character="character"
  />
  <Footer />
</template>


<script>
import getCharactersData from "./service/CharactersRepository.js";
import CharacterCard from "./components/CharacterCard.vue";
import Footer from "./components/Footer.vue";
import Header from "./components/Header.vue";
import SideBar from "./components/AZFilter.vue";

export default {
  name: "CharactersGallery",

  //components: {
  //  CharacterCard,
  //  Footer,
  //  Header,
  // SideBar,
  //},

  data() {
    return {
      charactersData: [],
      characters: [],
      filteredCharacters: [],
    };
  },
  mounted() {
    this.getCharacterData();
  },
  methods: {
    async getCharacterData() {
      const response = await fetch(
        "https://api.disneyapi.dev/character?page=2&pageSize=50"
      );
      try {
        const data = await response.json();
        this.characters = data;
        // this.filteredCharacters = data;
      } catch (error) {
        console.error("Error fetching rocket data:", error);
      }
    },

    // async getCharacterData() {
    //     const response = await fetch("https://api.disneyapi.dev/character?page=2&pageSize=50")
    //     if (response.status == 200) {
    //         const data = await response.json()
    //         return data.characters
    //     } else {
    //         console.error('Error fetching character data:', error);
    //     }
    // },

    handleFilterChange(filteredCharacters) {
      // Update filteredCharacters when filters change
      this.filteredCharacters = filteredCharacters;
      console.log(this.filteredCharacters);
    },
  },
};
</script>

<style>
body {
  background: linear-gradient(to bottom, #83d6c3, #7cacfb);
  font-family: "Arial", sans-serif;
  /* SÛRE ? */
  text-align: center;
  margin: 0;
  padding: 0;
  padding-top: 200px;
  padding-bottom: 50px;
}
</style>