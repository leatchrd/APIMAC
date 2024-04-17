// EN COURS, FINAL
// note : SideBar, characters

<template>
  <header>
    <h1>{{ title }}</h1>
    <SideBar :characters="characters" @filter-change="handleFilterChange" />
  </header>
</template>

<script>
import SideBar from './AZFilter.vue';

export default {
  data() {
    return {
      title: "Awesome Disney Characters",
    };
  },
  components: {
    SideBar,
  },
  props: {
    characters: {
      type: Array, // SÛRE ?
      required: true
    }
  },
  methods: {
    handleFilterChange(filteredCharacters) { // SÛRE ?
      this.$emit('filter-change', filteredCharacters); // SÛRE ?
    }
  }
};
</script>

<style scoped>
header {
  background: linear-gradient(to bottom, #83d6c3, #7cacfb);
  color: #fff;
  padding: 10px;
  text-align: center;
  width: 100%;
  /* position: fixed;
  top: 0;
  left: 0;
  z-index: 1000; */
}
</style>