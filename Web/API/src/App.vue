<template>
  <div>
    <Background />
    <div class="container">
      <h1>Gravity Falls Characters</h1>
      <CharacterGrid />
    </div>
  </div>
</template>

<script>
import Background from '@/components/Background.vue';
import CharacterGrid from '@/components/CharacterGrid.vue';

export default {
  components: {
    Background,
    CharacterGrid
  }
};
</script>

<style>
.container {
  max-width: 1200px;
  margin: 0 auto;
  padding: 20px;
}
</style>
