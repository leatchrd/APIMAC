
<template>
  <div id="app">
    <Background :characters="randomCharacters" />
  </div>
</template>

<script>
import Background from './components/Background.vue';

export default {
  components: {
    Background
  },
  data() {
    return {
      characters: []
    };
  },
  computed: {
    randomCharacters() {
      const shuffledCharacters = this.shuffle(this.characters);
      return shuffledCharacters.slice(0, 18);
    }
  },
  mounted() {
    fetch('https://api.disneyapi.dev/character')
      .then(response => response.json())
      .then(data => {
        if (data && Array.isArray(data.data)) {
          this.characters = data.data;
        } else {
          console.error('Invalid response data format');
        }
      })
      .catch(error => console.error('Error fetching characters', error));
  },
  methods: {
    shuffle(array) {
      for (let i = array.length - 1; i > 0; i--) {
        const j = Math.floor(Math.random() * (i + 1));
        [array[i], array[j]] = [array[j], array[i]];
      }
      return array;
    }
  }
};
</script>

<style>
#app {
  text-align: center;
}
</style>
