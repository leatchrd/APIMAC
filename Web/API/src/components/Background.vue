
<template>
  <div class="grid">
    <CharacterCard
      v-for="(character, index) in characters"
      :key="character._id || index"
      :character="character"
    />
  </div>
</template>

<script>
import CharacterCard from "./CharacterCard.vue";

export default {
  props: {
    characters: {
      type: Array,
      required: true,
    },
  },
  components: {
    CharacterCard,
  },
};
</script>

<style>
.grid {
  /* Faire une grille de cartes */
  display: grid;
  width: 100%;
  grid-template-columns: repeat(3, 1fr);
  grid-gap: 20px; /* Espace entre deux cards */
    /* grid-row: auto; */
  padding: 50px; /* Espace autour des cards */
  padding-block-start: 20px;
  min-height: 50px; /* Hauteur des cards */
}

.card {
  /* Faire une carte */ /* Pas utilisé pour l'instant*/
  border-radius: 3px;
  background: white;
  color: black;
  padding: 10px;
}
</style>