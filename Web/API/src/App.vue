
<template>
  <div id="app">
    <Background :characters="characters" />
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
  mounted() {
    fetch('https://api.disneyapi.dev/character')
      .then(response => response.json())
      .then(data => {
        if (data && Array.isArray(data.data)) {
          this.characters = data.data.slice(0, 20);
        } else {
          console.error('Invalid response data format');
        }
      })
      .catch(error => console.error('Error fetching characters', error));
  }
};
</script>

<style>
#app {
  text-align: center;
}
</style>
