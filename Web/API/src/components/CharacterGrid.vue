<template>
  <div class="character-grid">
    <CharacterCard v-for="character in characters" :key="character.id" :character="character" />
  </div>
</template>

<script>
import CharacterCard from '@/components/CharacterCard.vue';

export default {
  components: {
    CharacterCard
  },
  data() {
    return {
      characters: []
    };
  },
  mounted() {
    this.fetchCharacters();
  },
  methods: {
    async fetchCharacters() {
  fetch('https://gravity-falls-api.vercel.app/api/characters', {
    method: 'GET',
    mode: 'cors',
    headers: {
      'Content-Type': 'application/json'
    },
  })
    .then(response => {
      if (!response.ok) {
        throw new Error('Network response was not ok');
      }
      return response.json();
    })
    .then(data => {
      this.characters = data;
      this.characters = data.slice(0, 3); // Limité à 3 personnages pour le moment
    })
    .catch(error => {
      console.error('Error fetching characters:', error);
    });
}
}
};
</script>



<style>
.character-grid {
  display: grid;
  grid-template-columns: repeat(3, 1fr);
  gap: 20px;
}
</style>
