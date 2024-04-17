<template>
  <div class="header">
    <input
      type="text"
      v-model="searchQuery"
      @keyup.enter="search"
      placeholder="Rechercher un personnage Disney"
    />
    <button @click="search"><i class="fas fa-search"></i></button>
  </div>
</template>
  
  <script>
export default {
  data() {
    return {
      searchQuery: "",
    };
  },
  methods: {
    search() {
      this.$emit("search", this.searchQuery.trim());
    },
  },
};
</script>
  
  <style>
.header {
  background-color: white;
  border-radius: 20px;
  padding: 10px 20px;
}

input[type="text"] {
  flex: 1;
  border: none;
  outline: none;
  padding: 5px 10px;
  border-radius: 20px;
}

button {
  border: none;
  background-color: #7cacfb;
  cursor: pointer;
  padding: 5px;
}
</style>
  