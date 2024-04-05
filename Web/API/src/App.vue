<template>
  <div class="background">
    <div class="container">
      <h1>Gravity Falls Characters</h1>
      <CharacterGrid />
    </div>
  </div>
</template>

<script>
import CharacterGrid from '@/components/CharacterGrid.vue';

export default {
  components: {
    CharacterGrid
  }
};
</script>

<style>
.background {
  background: #735E59;
  background: -webkit-linear-gradient(to bottom, #AD795B, #735E59);
  background: linear-gradient(to bottom, #AD795B, #735E59);
  background-size: cover;
  background-position: center;
  background-repeat: no-repeat;
  background-attachment: fixed;
  height: 100vh;
  display: flex;
  align-items: center;
  justify-content: center;
}
</style>
