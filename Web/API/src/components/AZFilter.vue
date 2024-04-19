// EN COURS, FINAL

<template>
  <div class="az-filter">
    <label for="character-sort">Sort by:</label>
    <select :value="NameSort" @input="AZSort" id="character-sort">
      <option name="AZName" value="AZName">Name A - Z</option>
      <option name="ZAName" value="ZAName">Name Z - A</option>
    </select>
  </div>
</template>

<script>
export default {
  name: "AZFilter",
  props: {
    NameSort: String,
  },
  emits: ["update:NameSort"],
  watch: {
    NameSort: function (newNameSort) {
      localStorage.setItem("NameSort", newNameSort);
    },
  },
  methods: {
    AZSort: function (event) {
      this.$emit("update:NameSort", event.target.value);
    },
  },
};
</script>

<style>
.az-filter {
  display: flex;
  margin: 10px;
  margin-bottom: 20px;
}
@media (min-width: 300px) and (max-width: 800px) {
  .az-filter {
    position: absolute;
    padding-top: 50px;
  }
}
</style>