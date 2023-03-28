<template>
	<div class="h-screen flex flex-col items-stretch">
		<div class="h-14 flex-none"></div>
		<div class="flex-grow max-h-screen grid grid-cols-3 bg-[#282c34] border-y-2 border-black/60">
                        <div class="border-r-2 border-black/60">
			<QuestionSection />
                </div>
                        <div class="flex flex-col items-stretch border-r-2 border-black/60">
                        <div class="h-12 bg-black/20 flex-none flex items-stretch text-[13px] justify-between"><div class="flex-grow flex"><button class="flex items-center justify-center h-12 w-12 flex-none"><Icon name="lucide:folder" size="18"/></button><div class="flex items-center justify-center h-12 pl-2 pr-4 gap-2 bg-[#282c34] flex-none whitespace-nowrap"><button class="opacity-60"><Icon name="lucide:x" size="12"/></button><span>main.c</span></div><button class="flex items-center justify-center h-12 w-12 flex-none"><Icon name="lucide:plus" size="18"/></button></div><button class="flex items-center justify-center h-12 w-12 flex-none"><Icon name="lucide:maximize-2" size="18"/></button></div>
			<CodeMirror />
                        <div class="flex items-center px-4 py-4 bg-black/20"><button class="bg-yellow-500 px-4 py-2 rounded font-medium text-black">Run</button></div>
                </div>
                        <div class="flex flex-col">
                                <div class="h-12 bg-black/20 flex-none flex items-stretch text-[13px] justify-between"><div class="flex-grow flex"><button class="flex items-center justify-center h-12 w-12 flex-none"><Icon name="lucide:plus" size="18"/></button><div class="flex items-center justify-center h-12 pl-2 pr-4 gap-2 bg-black/30 flex-none whitespace-nowrap"><button class="opacity-60"><Icon name="lucide:x" size="12"/></button><span>main.c</span></div></div><button class="flex items-center justify-center h-12 w-12 flex-none"><Icon name="lucide:maximize-2" size="18"/></button></div>
                                <div class="flex-grow flex flex-col"><div class="flex-grow bg-black/50"></div></div>
                </div>
		</div>
		<div class="h-14 flex-none"></div>
	</div>
</template>
