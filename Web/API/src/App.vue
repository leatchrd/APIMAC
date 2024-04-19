// PB : NO DISPLAY OF THE GALLERY CARD
// LATER : ADD SEARCH OPTION

<template>
  <div>
    <Header :characters="characters" @filter-change="handleFilterChange" />
    <Gallery :characters-gallery="displayedCharacters" />
    <Footer />
  </div>
</template>

<script>
import getCharactersData from "./service/CharactersRepository.js";
import Gallery from "./components/CharactersGallery.vue";
import CharacterCard from "./components/CharacterCard.vue";
import Footer from "./components/Footer.vue";
import Header from "./components/Header.vue";
import SideBar from "./components/AZFilter.vue";

export default {
  components: {
    CharacterCard,
    Footer,
    Header,
    SideBar,
  },

  data() {
    return {
      charactersData: [],
      characters: [],
      displayedCharacters: [],
      filteredCharacters: [],
    };
  },

  mounted() {
    this.getCharacterData();
  },

  methods: {
    async getCharacterData() {
      this.charactersData = await getCharactersData();
      console.log(this.character); // TO DELETE
      this.characters = this.charactersData;
    },
  },

  handleFilterChange(filteredCharacters) {
    this.filteredCharacters = filteredCharacters;
    console.log(this.filteredCharacters);
  },
};
</script>

<style>
body {
  background: linear-gradient(to bottom, #83d6c3, #7cacfb);
  font-family: "Arial", sans-serif;
  text-align: center;
  margin: 0;
  padding: 0;
  padding-bottom: 50px;
}
</style>