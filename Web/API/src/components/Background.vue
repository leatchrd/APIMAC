<template>
  <div class="background">
    <!-- Contenu de l'arrière-plan -->
  </div>
</template>

<script>
export default {
  // Ajoutez vos données, méthodes, etc.
};
</script>

<style scoped>
.background {
  background-image: url('@/assets/APIBackground.jpg');
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
  z-index: -1;
}
</style>
