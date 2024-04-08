
<template>
  <div class="background">
    <CharacterCard v-for="(character, index) in characters" :key="character._id || index" :character="character" />
  </div>
</template>

<script>
import CharacterCard from './CharacterCard.vue';

export default {
  props: {
    characters: {
      type: Array,
      required: true
    }
  },
  components: {
    CharacterCard
  }
};
</script>

<style>
.background {
  display: grid;
  grid-template-columns: repeat(3, 1fr);
  gap: 20px;
  padding: 20px;
  min-height: 100vh;
}
</style>
