
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
import CharacterCard from "./CharacterCard.txt";

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
</style>