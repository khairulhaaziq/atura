<template>
	<codemirror
		v-model="code"
		placeholder="Code goes here..."
		class="[&>*]:h-full [&>*]:pt-4 text-base"
		:autofocus="true"
		:indent-with-tab="false"
		:tab-size="2"
		:extensions="extensions"
		@ready="handleReady"
		@change="log('change', $event)"
		@focus="log('focus', $event)"
		@blur="log('blur', $event)"
	/>
</template>

<script setup lang="ts">
import { Codemirror } from "vue-codemirror";
import { javascript } from "@codemirror/lang-javascript";
import { indentWithTab } from "@codemirror/commands";
import { keymap } from "@codemirror/view";
import { cpp } from "@codemirror/lang-cpp";
import { oneDark } from "@codemirror/theme-one-dark";
import { indentationMarkers } from '@replit/codemirror-indentation-markers';

const code = ref(`#include <stdio.h>\n\nint main(void)\n{\n\tprintf("Hello, world!")\n}`);

const extensions = [
	cpp(),
	oneDark,
	indentationMarkers(),
	keymap.of([
		{
			key: "Tab",
			run: function (view) {
				const tabWidth = 2;
				const { state, dispatch } = view;
				const { from, to } = state.selection.main;
				const lineStart = state.doc.lineAt(from).from;
				const currentIndent = from - lineStart;

				let spacesToAdd;
				if (currentIndent % tabWidth === 1) {
					spacesToAdd = 1;
				} else {
					spacesToAdd = tabWidth;
				}

				const spaces = " ".repeat(spacesToAdd);
				dispatch({
					changes: { from, to, insert: spaces },
					selection: {
						anchor: from + spaces.length,
					},
					scrollIntoView: true,
				});
				return true;
			},
			preventDefault: true,
		},
	]),
];

const view = shallowRef();
const handleReady = (payload) => {
	view.value = payload.view;
};

function log(name, event) {
	console.log(name, event);
}

const getCodemirrorStates = () => {
	const state = view.value.state;
	const ranges = state.selection.ranges;
	const selected = ranges.reduce(
		(r, range) => r + range.to - range.from,
		0
	);
	const cursor = ranges[0].anchor;
	const length = state.doc.length;
	const lines = state.doc.lines;
};
</script>
