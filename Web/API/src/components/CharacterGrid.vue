
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
        try {
          const response = await fetch('https://gravity-falls-api.vercel.app/api/characters');
          const data = await response.json();
          this.characters = data;
        } catch (error) {
          console.error('Error fetching characters:', error);
        }
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
  