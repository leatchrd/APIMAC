// DON'T WORK HERE

<template>
  <div class="grid">
    <CharacterCard
      v-for="(character, index) in characters":key="character._id || index":character="character"
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
  display: grid;
  width: 100%;
  grid-template-columns: repeat(3, 1fr);
  grid-gap: 20px;
  /* grid-row: auto; */
  padding: 50px;
  padding-block-start: 20px;
  min-height: 50px;
}
</style>